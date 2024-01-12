#!/bin/bash
docker compose --file docker-compose.build.yml build
docker compose --file docker-compose.build.yml up
