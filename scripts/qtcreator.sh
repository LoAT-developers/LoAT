#!/bin/bash
docker compose -f ../docker/docker-compose.yml build --build-arg TOKEN="$(xauth list)"
docker compose -f ../docker/docker-compose.yml up
