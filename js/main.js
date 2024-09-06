// @ts-check
"use strict";

(/* Image upload logic */() => {
  /** @type {HTMLFormElement | null} */
  const imgForm = document.querySelector('#img-form')
  if (!imgForm) return

  /** @type {HTMLInputElement | null} */
  const imgFile = document.querySelector('#img-file')
  if (!imgFile) return

  /** @type {HTMLCanvasElement | null} */
  const imgResult = document.querySelector('#img-result')
  if (!imgResult) return

  imgFile.removeAttribute('disabled')

  imgFile.addEventListener('change',
    /**
     * Reads data from the uploaded file.
     *
     * @param {Event} e
     *   The event.
     *
     * @listens HTMLChangeEvent
     */
    async (e) => {
      /** @type {(EventTarget & {files?: FileList}) | null} */
      const target = e.target

      if (!target || !target.files?.length) return

      const file = target.files[0]
      const fileBytes = new Uint8Array(await file.arrayBuffer())
      const buffer = globalThis.Module._malloc(fileBytes.length)

      globalThis.Module.HEAPU8.set(fileBytes, buffer)
      globalThis.Module.ccall(
        'decode_img',
        null,
        ['number', 'number'],
        [buffer, fileBytes.length],
      );

      globalThis.Module._free(buffer)
      imgForm.reset()
    }
  )
})()
