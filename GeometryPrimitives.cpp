#include "GeometryPrimitives.h"

std::vector<Vertex> GeometryPrimitives::createCubeVertices()
{
    std::vector<Vertex> cubeVertices;

    // Define the 8 unique vertices of the cube
    glm::vec3 positions[] = {
        {-0.5f, -0.5f, -0.5f}, // 0
        { 0.5f, -0.5f, -0.5f}, // 1
        { 0.5f,  0.5f, -0.5f}, // 2
        {-0.5f,  0.5f, -0.5f}, // 3
        {-0.5f, -0.5f,  0.5f}, // 4
        { 0.5f, -0.5f,  0.5f}, // 5
        { 0.5f,  0.5f,  0.5f}, // 6
        {-0.5f,  0.5f,  0.5f}  // 7
    };

    // Define the normals for each face of the cube
    glm::vec3 normals[] = {
        { 0.0f,  0.0f, -1.0f}, // Front face
        { 0.0f,  0.0f,  1.0f}, // Back face
        {-1.0f,  0.0f,  0.0f}, // Left face
        { 1.0f,  0.0f,  0.0f}, // Right face
        { 0.0f, -1.0f,  0.0f}, // Bottom face
        { 0.0f,  1.0f,  0.0f}  // Top face
    };

    // Define a color for each face
    glm::vec3 colors[] = {
        {1.0f, 0.0f, 0.0f}, // Red
        {0.0f, 1.0f, 0.0f}, // Green
        {0.0f, 0.0f, 1.0f}, // Blue
        {1.0f, 1.0f, 0.0f}, // Yellow
        {1.0f, 0.0f, 1.0f}, // Magenta
        {0.0f, 1.0f, 1.0f}  // Cyan
    };

    // Define the indices for the 12 triangles of the cube
    unsigned int indices[] = {
        0, 1, 2,  2, 3, 0,  // Front face
        4, 5, 6,  6, 7, 4,  // Back face
        0, 3, 7,  7, 4, 0,  // Left face
        1, 5, 6,  6, 2, 1,  // Right face
        0, 1, 5,  5, 4, 0,  // Bottom face
        3, 2, 6,  6, 7, 3   // Top face
    };

    // Construct the vertex data for each triangle
    for (int i = 0; i < 36; i++)
    {
        unsigned int index = indices[i];
        int face = i / 6; // Determine the face based on the triangle index

        Vertex vertex;
        vertex.position = positions[index];
        vertex.normal = normals[face];
        vertex.color = colors[face];

        cubeVertices.push_back(vertex);
    }

    return cubeVertices;
}
