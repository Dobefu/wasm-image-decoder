// @ts-check
"use strict";

(/* Image upload logic */() => {
  const imgFile = document.querySelector('#img-file')
  if (!imgFile) return

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

      imgResult.innerHTML = JSON.stringify(fileBytes)
    }
  )
})()
