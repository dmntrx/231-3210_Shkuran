FROM python:3.11.11-slim-bullseye

ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1

# каталог, который будет корнем для копирования файлов и для запуска команд внутри файла
WORKDIR /backend

# скопировать в /backend список пакетов и установить его в образ
COPY requirements.txt .
RUN pip install -r requirements.txt

# скопировать остальные файлы бекенда в "."
COPY . .

# послойно, сначала только requirements.txt, чтобы при каждом перезапуске
# не перекачивать зависимости для малейших изменений, заново не будет ставить пакеты