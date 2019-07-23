
type rvm >/dev/null 2>/dev/null || echo ${PATH} | __rvm_grep "/usr/local/rvm/bin" > /dev/null || export PATH="${PATH}:/usr/local/rvm/bin"
