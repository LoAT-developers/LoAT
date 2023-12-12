#!/bin/bash
docker compose build --build-arg TOKEN="$(xauth list)"
docker compose up
