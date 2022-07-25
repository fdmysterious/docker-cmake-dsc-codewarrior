#!/bin/bash

set -e # Exit on first error
#set -x # Enable debugging of commands

tmpfolder=`mktemp -d`

# Cleanup

cleanup() {
	rm -rf "${tmpfolder}"
}

trap cleanup EXIT


# Log functions

log_info() {
    printf "I:$*\n" >> /dev/stderr
}

log_error() {
    printf "E:$*\n" >> /dev/stderr
}

exit_error() {
    code=$1
    shift
    log_error "$*"
    exit ${code}
}


# Utilities

find_in_archive() {
    log_info "Try to find file containing \"$2\" in archive \"$1\""
    fmatch=`7z l "$1" | grep "$2" | head -n 1`
    fname="${fmatch##* }"

    if [ -z "${fname}" ] ; then
        exit_error 1 "Could not find file with pattern \"$2\" in archive \"$1\" "
    fi
    
    echo "$fname"
}


# Main extraction stuff

zip_file="$1"

if [ -z $zip_file ] ; then
    exit_error 1 "Please give input file path"
fi

output_dir="$2"

if [ -z $output_dir ] ; then
	exit_error 1 "Please give output directory"
fi

log_info "Try to extract dsc update from .exe"
dsc_fname=$(find_in_archive "$zip_file" "dsc.updatesite")
log_info "Found DSC update archive: ${dsc_fname}"
7z e "${zip_file}" "${dsc_fname}" -o${tmpfolder}

log_info "Try to extract build tools from DSC update archive"
buildtools_fname=$(find_in_archive "${tmpfolder}/${dsc_fname}" "buildtools_root")
log_info "Found buildtools: ${buildtools_fname}"
7z e "${tmpfolder}/${dsc_fname}" "${buildtools_fname}" -o${tmpfolder}

log_info "Extract build tools..."
mkdir -p "${output_dir}" # Create folder, no error if already existing
rm "${output_dir}/*" -rf # Clean folder if needed
7z x "${tmpfolder}/${buildtools_fname##*/}" -o${output_dir}
rm -r "${output_dir}/META-INF"
