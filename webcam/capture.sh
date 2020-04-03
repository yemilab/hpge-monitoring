#!/bin/bash

set +e

DATETIME=`date +%Y%m%d-%H%M%S`
DATADIR="./images"
IMGPATH="${DATADIR}/webcamshot-${DATETIME}.jpg"

[ ! -d ${DATEDIR} ] && mkdir ${DATADIR}

fswebcam -r 640x480 --jpeg 85 -D 1 ${IMGPATH}

cp ${IMGPATH} gasflow.jpg
curl -F "gasflow=@${IMGPATH}" ${URL}/gasflow
