# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acyrenna <acyrenna@school21.ru>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 23:40:16 by acyrenna          #+#    #+#              #
#    Updated: 2021/01/09 15:21:46 by acyrenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.15.3)

project(libft)

set(BUILD_FLAGS "-O3")
set(DST_NAME ft)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/sources/)
set(INC_DIR ${PROJECT_SOURCE_DIR}/includes/)
option(COMPILE_SO "COMPILE_SO" OFF)

MACRO(INCLUDE_DIRS return_list)
	FILE(GLOB_RECURSE new_list ${INC_DIR}*.h)
	SET(dir_list "")
	FOREACH(file_path ${new_list})
		GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
		SET(dir_list ${dir_list} ${dir_path})
	ENDFOREACH()
	LIST(REMOVE_DUPLICATES dir_list)
	SET(${return_list} ${dir_list})
ENDMACRO()

set(INC_DIRS ./)
INCLUDE_DIRS(INC_DIRS)

FILE(GLOB_RECURSE LIBFT_SOURCES ${SRC_DIR}*.c)
FILE(GLOB_RECURSE LIBFT_HEADERS ${INC_DIR}*.h)

if (COMPILE_SO)
    add_library(${PROJECT_NAME} SHARED ${LIBFT_SOURCES} ${LIBFT_HEADERS})
else()
    add_library(${PROJECT_NAME} STATIC ${LIBFT_SOURCES} sources/ft_lstfree.c)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${INC_DIRS})
set_target_properties(${PROJECT_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
	ARCHIVE_OUTPUT_NAME  ${DST_NAME}
	COMPILE_FLAGS ${BUILD_FLAGS})
