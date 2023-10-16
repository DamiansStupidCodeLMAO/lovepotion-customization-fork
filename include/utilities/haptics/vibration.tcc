#pragma once

#include <common/console.hpp>
#include <common/object.hpp>

#include <limits>
#include <memory>
#include <stddef.h>

namespace love
{
    template<Console::Platform T = Console::ALL>
    class Vibration
    {
      public:
        static constexpr uint32_t MAX           = std::numeric_limits<uint32_t>::max();
        static constexpr float HAPTYIC_INFINITY = -1.0f;

        static Type type;

        struct VibrationInfo
        {
            float left;
            float right;

            float endTime;
        };

        Vibration() : vibrationInfo {}
        {}

        void SetDuration(float duration)
        {
            this->vibrationInfo.endTime = duration;
        }

        float GetDuration()
        {
            return this->vibrationInfo.endTime;
        }

        void GetValues(float& left, float& right)
        {
            left  = this->vibrationInfo.left;
            right = this->vibrationInfo.right;
        }

        void SendValues(float left, float right)
        {}

        bool Stop()
        {
            return true;
        }

      protected:
        VibrationInfo vibrationInfo;
        int handleCount;
    };
} // namespace love
