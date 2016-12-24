#pragma once 
#ifndef __MATERIA_H__
#define __MATERIA_H__

#include "Object.h"
#include "Color.h"

namespace engine
{
    enum MateriaType {
        //纯色
        Purity,
        //彩色
        Multicolor,
        //贴图
        Chartlet
    };

    class Materia : public Object
    {
    public:
        CREATEFUNC(Materia);
        static const Materia & defaultMateria(void);

        static const Materia & Create(const ColorRGBA & c);
        static const Materia & Create(const ColorRGBA * colors, const unsigned int count);

        const bool color(const ColorRGBA & c);
        const ColorRGBA & color(void) const;
        
        const bool colors(const ColorRGBA * colors, const unsigned int count);
        const ColorRGBA * colors(void) const;
        const unsigned int colorsCount(void) const; 

        const MateriaType &  materiaType(void) const;
    protected:
        Materia(void);
        virtual ~Materia(void);
        const bool init(void) override;
    private:
        void clearData(void);

        ColorRGBA m_color;
        ColorRGBA * m_colors;
        unsigned int m_colorsCount;
        MateriaType m_materiaType; 

    };
}

#endif //__MATERIA_H__