#!/bin/bash
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
docker compose -f $SCRIPT_DIR/../docker/docker-compose.yml build --build-arg TOKEN="$(xauth list)"
docker compose -f $SCRIPT_DIR/../docker/docker-compose.yml up
