#pragma once

#include <optional>

namespace Filip::Physics {

    struct Vector2 {
    // ==============================
    //      Variabile publice
    // ==============================

    public:
        float x,y;

    // ==============================
    //      Metode publice
    // ==============================

    public:
        Vector2& set(const float x, const float y);
        Vector2& normalize();
        Vector2& add(const Vector2& other);
        Vector2& subtract(const Vector2& other);
        Vector2& scaleBy(float scalar);
        Vector2& rotateBy(const float radians);

        Vector2 normalized() const;
        Vector2 rotatedBy(const float scalar) const;
        float lenght() const;
        float sinTheta() const;
        float cosTheta() const;

        inline bool isZero() const { return ( (x == 0) && (y == 0) ); }


    // ==============================
    //      Operatori
    // ==============================

    public:
        inline Vector2 operator + () const { return Vector2(*this); }
        inline Vector2 operator - () const { return Vector2(this->y, this->x); }

        inline Vector2& operator += (const Vector2& other) { return this->add(other); }
        inline Vector2& operator -= (const Vector2& other) { return this->subtract(other); }
        inline Vector2& operator *= (const float scalar) { return this->scaleBy(scalar); }
        inline Vector2& operator /= (const float scalar) { return this->scaleBy(1/scalar); }
        
        bool operator == (const Vector2& other);
        bool operator != (const Vector2& other);
        
        Vector2 operator + (const Vector2& other);
        Vector2 operator - (const Vector2& other);
        Vector2 operator * (const float scalar);
        Vector2 operator / (const float scalar);

    // ==============================
    //      Constructori si Destructor
    // ==============================

    public:
        Vector2(float x = 0, float y = 0);
        Vector2(const Vector2& src);

        ~Vector2();

    // ==============================
    //      Variabile private
    // ==============================

    private:
        struct Cache {
            mutable Vector2* normalized = new Vector2;
            mutable std::optional<float> lenght;
            mutable std::optional<float> sinTheta;
            mutable std::optional<float> cosTheta;

            void invalidate() 
            {
                normalized->set(0,0);
                lenght.reset();
                sinTheta.reset();
                cosTheta.reset();
            }
        } cache;

    // ==============================
    //      Constants
    // ==============================

    };
}