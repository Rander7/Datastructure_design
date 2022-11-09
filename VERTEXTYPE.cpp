#include "VERTEXTYPE.h"
#include "UNDIRECTED_GRAPH.h"

VERTEXTYPE::VERTEXTYPE(int number, const char* name, const char* information, bool existence)
{
    m_number = number;
    m_existence = existence;
    strcpy(m_name, name);
    strcpy(m_information, information);
}

int VERTEXTYPE::get_vex_number()
{
    return m_number;
}

char* VERTEXTYPE::get_vex_name()
{
    return m_name;
}

char* VERTEXTYPE::get_vex_information()
{
    return m_information;
}

bool VERTEXTYPE::get_vex_existence()
{
    return m_existence;
}

void VERTEXTYPE::change_vex_number(int number)
{
    m_number = number;
}

void VERTEXTYPE::change_vex_name(const char* name)
{
    strcpy(m_name, name);
}

void VERTEXTYPE::change_vex_information(const char* information)
{
    strcpy(m_information, information);
}

void VERTEXTYPE::change_vex_existence(bool existence)
{
    m_existence = existence;
}


