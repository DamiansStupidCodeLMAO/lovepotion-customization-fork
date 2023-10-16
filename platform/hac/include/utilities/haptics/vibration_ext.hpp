#pragma once

#include <utilities/haptics/vibration.tcc>

#include <switch.h>

namespace love
{
    template<>
    class Vibration<Console::HAC> : public Vibration<Console::ALL>
    {
      public:
        Vibration()
        {}

        Vibration(HidNpadIdType playerId, HidNpadStyleTag style);

        Vibration& operator=(Vibration&& other);

        virtual ~Vibration();

        bool SendValues(float left, float right);

        bool Stop();

      private:
        std::unique_ptr<HidVibrationDeviceHandle[]> handles;

        HidNpadIdType playerId;
        HidNpadStyleTag style;
    };
} // namespace love
