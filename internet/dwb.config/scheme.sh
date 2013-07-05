#!/bin/bash

case ${DWB_SCHEME} in
  mailto) open -t terminal -e "mutt ${DWB_URI}";;
  ftp)open -t terminal -e "ncftp ${DWB_URI}";;
  *) open -v ${DWB_URI}
esac
