
ORIGINAL_DIR=${PWD}

# establish the script directory absolute path

UTILITY_ENV_FILE=${BASH_SOURCE[0]}
UTILITY_DIR=`dirname ${UTILITY_ENV_FILE}`
cd ${UTILITY_DIR}
UTILITY_DIR=`pwd`
cd ${ORIGINAL_DIR}

# path

#export PATH=:${PATH}

# exportable aliases

export UTILITY_DIR
mgit () { ${UTILITY_DIR}/build/meta_git.exe $* ; }
export -f mgit
