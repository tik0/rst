#!/bin/sh

(
    cd ../proto/

    RELEASE_TAG=release-0.15
    RELEASE_TIME=$(git --no-pager log --max-count 1 --pretty="format:%cd" "${RELEASE_TAG}^")

    files=$(find sandbox -type f -name '*.proto' -not -name '__package.proto')

    log() {
        git --no-pager log --follow "$@"
    }

    echo "Based on release ${RELEASE_TAG} at ${RELEASE_TIME}"
    for file in ${files} ; do
        echo "${file}"
        if ! [ $(log --until "${RELEASE_TIME}" --pretty="format:%cd" -- "${file}" | wc -l) = 0 ] ; then
           echo "  Added"
           log --reverse --pretty="format:    %cd %s%n" -- "${file}" | head -n 1
           echo "  History after release"
           log --since "${RELEASE_TIME}" --pretty="format:    %cd %s%n" -- "${file}"
        else
            echo "  Too new"
        fi
        echo ""
    done

)
