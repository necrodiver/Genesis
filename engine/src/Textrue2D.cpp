#include "Textrue2D.h"
#include "Image.h"

namespace engine
{
    Textrue2D & Textrue2D::Create(const string & fileName)
    {
        Textrue2D & result = Create();

        bool textrue2DInit = result.init(fileName);

        assert(textrue2DInit);

        if(!textrue2DInit){ result.initializeError(-1); }
        
        return result;
    }

    Textrue2D & Textrue2D::Create(const Image & img)
    {
        Textrue2D & result = Create();

        bool textrue2DInit = result.init(img);

        assert(textrue2DInit);

        if(!textrue2DInit){ result.initializeError(-1); }
        
        return result;
    }


    const bool Textrue2D::init(void)
    {
        if(!Object::init()){ return false; }
        m_textrueId = 0;
        return true;
    }

    const bool Textrue2D::init(const string & fileName)
    {
        Image & sourceImage = Image::Create(fileName);

        if(!init(sourceImage)){ return false; }

        return true;
    }

     const bool Textrue2D::init(const Image & img)
     {

        if(!img.ready()){ return false; }

        //创建纹理
        glGenTextures(1, &m_textrueId);
        //绑定纹理
        glBindTexture(GL_TEXTURE_2D, m_textrueId);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width(), img.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.data());
        glGenerateMipmap(GL_TEXTURE_2D);

        //解绑纹理
        glBindTexture(GL_TEXTURE_2D, 0);

         return true;
     }
    
}