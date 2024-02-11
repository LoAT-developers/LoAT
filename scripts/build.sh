#!/bin/bash
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
docker compose --file $SCRIPT_DIR/../docker/docker-compose.build.yml build
docker compose --file $SCRIPT_DIR/../docker/docker-compose.build.yml up
