
# Previously source ../env.bash

targets = [

    { "name" : "LONG_NAME_help" , "command" : "SHORT_NAME --help" },

]

# Filtres

run_filters_out = [
]

diff_filters_in = [
  {"name": "all", "re": "^(.*)$", "apply": "%"}
]

