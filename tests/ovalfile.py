
# Previously source ../env.bash

targets = [

    { "name" : "meta_git_help" , "command" : "mgit --help" },

]

# Filtres

run_filters_out = [
]

diff_filters_in = [
  {"name": "all", "re": "^(.*)$", "apply": "%"}
]

