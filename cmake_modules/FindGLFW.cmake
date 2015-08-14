# FindGLFW GLFW3 library
# GLFW_INCLUDE_DIR
# GLFW_LIBRARIES

# Set up linux search paths
set(HEADER_SEARCH_PATH
  /usr/local
  /opt/local
  /usr
  /opt
)
set(LIBRARY_SEARCH_PATH
  /usr/local
  /opt/local
  /usr
  /opt
)

find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h ${HEADER_SEARCH_PATH})

# Find glfw library
find_library(GLFW_LIBRARIES glfw3 ${LIBRARY_SEARCH_PATH})

mark_as_advanced(FORCE ${GLFW_INCLUDE_DIR} ${GLFW_LIBRARIES})

