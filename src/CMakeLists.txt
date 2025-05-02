# Discover all chapter subdirectories (e.g., chapter1, chapter2)
file(GLOB CHAPTER_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} chapter*/)

foreach(CHAPTER ${CHAPTER_DIRS})
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${CHAPTER}")
        add_subdirectory(${CHAPTER})
    endif()
endforeach()
