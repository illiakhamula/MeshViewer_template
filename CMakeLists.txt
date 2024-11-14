cmake_minimum_required(VERSION 3.10)
project(MeshViewer)

set(CMAKE_CXX_STANDARD 20)

# Пошук бібліотек
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

# Додавання виконуваного файлу
add_executable(MeshViewer
    main.cpp
	Vertex.h
    # необхідно додати файли до проєкту
	GeometryPrimitives.h
	GeometryPrimitives.cpp
    glad.c)

# Підключення бібліотек
target_link_libraries(MeshViewer PRIVATE glfw)

# Підключення папки із проектом, як джерела де шукати *.h\*.hpp файли
target_include_directories(MeshViewer PRIVATE ${CMAKE_SOURCE_DIR})

# Додавання директиви GLFW_INCLUDE_NONE до проекту,
# що дозволить не використовувати вбудовані функції OpenGL бібліотеки GLFW, оскільки в нас є glad
target_compile_definitions(MeshViewer PRIVATE GLFW_INCLUDE_NONE)

