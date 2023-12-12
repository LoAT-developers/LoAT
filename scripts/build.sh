#!/bin/bash
docker compose --file ../docker/docker-compose.build.yml build
docker compose --file ../docker/docker-compose.build.yml up
