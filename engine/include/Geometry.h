#pragma once
#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Node.h"
#include "Vec.h"
#include "Matrix.h"
#include "Materia.h"
#include "ShaderProgram.h"

namespace engine
{
    class Geometry : public Node
    {
    public:
        const bool bindMateria(Materia & m);
    protected:
        Geometry(void);
        virtual ~Geometry(void);
        const bool init(void) override;

        //指定数据大小
        void vertexsCount(const unsigned short count);
        void indiesCount(const unsigned short count);

        //获取数据大小
        const unsigned short vertexsCount(void) const;
        const unsigned short indiesCount(void) const;

        //修改指定位置数据
        void vertex(const unsigned short index, const Vec3 & data);
        void indie(const unsigned short index, const unsigned short data);

        //全部数据一次写入
        void vertexs(const Vec3 * data);
        void indies(const unsigned short * data);

        //指定位置写入指定长度的数据
        void vertexs(const Vec3 * data, const unsigned short count, const unsigned short startIndex = 0);
        void indies(const unsigned short * data, const unsigned short count, const unsigned short startIndex = 0);

        //数据起始地址
        const Vec3 * vertexs(void) const;
        const unsigned short * indies(void) const;

        //顶点对象
        const GLuint vertexArrayObject(void) const;
        //顶点数据缓存对象
        const GLuint vertexBufferObject(void) const;
        //顶点数据顺序对象
        const GLuint indiesBufferObject(void) const;

        const bool tick(const float dp) override;
        const bool draw(const Matrix4 & projection) override;
    private:

        //创建并使用当前设置所需要的着色器
        const bool updateShaderProgram(void);

        //顶点数据及顺序
        Vec3 * m_vertexs;
        unsigned short * m_indies;
        unsigned short m_vertexsCount, m_indiesCount;

        // string m_customVertextShaderFile, m_customFragmentShaderFile;
        
        //材质对象
        Materia * m_materia;

        //着色器对象
        ShaderProgram * m_shaderProgram;

        //gl对象
        GLuint m_vertexArrayObject, m_vertexBufferObject, m_indiesBufferObject;
        
    };
}

#endif //__GEOMETRY_H__