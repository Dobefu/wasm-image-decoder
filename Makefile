default: start

activate:
	@python3 -m venv ./venv
	. ./venv/bin/activate

start: activate
	python3 -m http.server
