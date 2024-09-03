//
// Created by avsom on 9/1/2024.
//

#pragma once

#include "Core.h"
#include <string>
#include <fstream>


struct OBJData
{

    std::vector<Vector3f> positions;
    std::vector<Vector2f> texture_coordinates;
    std::vector<Vector3f> vertex_normals;
    std::vector<std::array<Vector3u, 3>> faces;
};


class OBJImporter
{
public:

    static bool load_file(const char* file_name, OBJData &result)
    {
        std::ifstream obj_file;
        obj_file.open(file_name);
        if (!obj_file.is_open()) {
            return false;
        }
        while (!obj_file.eof()) {
            char line[line_size];
            obj_file.getline(line, line_size);
            parse_line(line, result);


        }
        obj_file.close();
        return true;
    };
private:

    static const int line_size = 256;
    enum OBJAttribute
    {
        position,
        face,
        vertex_normal,
        texture_coordinate,
        comment,
        discard
    };

    static OBJAttribute get_attribute_type(const char line[line_size])
    {
        if (line[0] == 'v' && line[1] == ' ') {
            return position;
        } else if (line[0] == 'v' && line[1] == 'n') {
            return vertex_normal;
        } else if (line[0] == 'v' && line[1] == 't') {
            return texture_coordinate;
        } else if (line[0] == 'f') {
            return face;
        } else if (line[0] == '#') {
            return comment;
        } else {
            return discard;
        }
    }


    static void parse_line(const char line[line_size], OBJData &result)
    {
        OBJAttribute attribute = get_attribute_type(line);
        switch (attribute) {
            case position: {
                Vector3f position;
                sscanf_s(line, "v %f %f %f", &position.x, &position.y, &position.z);
                result.positions.push_back(position);
                break;
            }
            case face: {
                const char* formatting_string = "f %lu/%lu/%lu %lu/%lu/%lu %lu/%lu/%lu";
                std::array<Vector3u, 3> face;
                sscanf_s(line, formatting_string,
                         &face[0].x, &face[0].y, &face[0].z,
                         &face[1].x, &face[1].y, &face[1].z,
                         &face[2].x, &face[2].y, &face[2].z);

                result.faces.push_back(face);
                break;
            }
            case vertex_normal: {
                Vector3f vertex_normal;
                sscanf_s(line, "vn %f %f %f", &vertex_normal.x, &vertex_normal.y, &vertex_normal.z);
                result.vertex_normals.push_back(vertex_normal);
                break;
            }
            case texture_coordinate:
                Vector2f texture_coordinate;
                sscanf_s(line, "vt %f %f", &texture_coordinate.x, &texture_coordinate.y);
                result.texture_coordinates.push_back(texture_coordinate);
                break;
            case comment:
                break;
            case discard:
                std::cout << "Discarded: " << line << "\n";
                break;
        }
    }


};

