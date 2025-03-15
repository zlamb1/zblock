#include <render/texture.hpp>

namespace GL
{
    class Texture2D : public ZG::Texture2D
    {
        public:
            Texture2D();
            virtual ~Texture2D(); 

            virtual bool BindTexture() override;

            virtual void SetImage(int width, int height, unsigned char *data) override; 
    };
}