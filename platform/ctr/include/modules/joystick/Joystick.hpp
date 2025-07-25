#pragma once

#include "modules/joystick/Joystick.tcc"

#include <3ds.h>

using HidKeyType = decltype(KEY_A);

namespace love
{
    class Joystick : public JoystickBase
    {
      public:
        Joystick(int id);

        Joystick(int id, int index);

        ~Joystick();

        virtual bool open(int64_t deviceId) override;

        virtual void close() override;

        virtual bool isConnected() const override;

        virtual float getAxis(GamepadAxis axis) const override;

        virtual std::vector<float> getAxes() const override;

        virtual bool isDown(std::span<GamepadButton> buttons) const override;

        virtual bool isHeld(std::span<GamepadButton> buttons) const override;

        virtual bool isUp(std::span<GamepadButton> buttons) const override;

        virtual bool isAxisChanged(GamepadAxis axis) const override;

        virtual void setPlayerIndex(int index) override;

        virtual int getPlayerIndex() const override;

        virtual JoystickInput getGamepadMapping(const GamepadInput& input) const override;

        virtual std::string getGamepadMappingString() const override;

        virtual bool isVibrationSupported() const override;

        virtual bool setVibration(float left, float right, float duration = -1.0f) override;

        virtual bool setVibration() override;

        virtual void getVibration(float& left, float& right) const override;

        virtual bool hasSensor(Sensor::SensorType type) const override;

        virtual bool isSensorEnabled(Sensor::SensorType type) const override;

        virtual void setSensorEnabled(Sensor::SensorType type, bool enable) override;

        virtual std::vector<float> getSensorData(Sensor::SensorType type) const override;

        enum HidAxisType
        {
            HIDAXIS_LEFTX        = KEY_CPAD_LEFT | KEY_CPAD_RIGHT,
            HIDAXIS_LEFTY        = KEY_CPAD_UP | KEY_CPAD_DOWN,
            HIDAXIS_RIGHTX       = KEY_CSTICK_LEFT | KEY_CSTICK_RIGHT,
            HIDAXIS_RIGHTY       = KEY_CSTICK_UP | KEY_CSTICK_DOWN,
            HIDAXIS_TRIGGERLEFT  = KEY_ZL,
            HIDAXIS_TRIGGERRIGHT = KEY_ZR
        };

        // clang-format off
        ENUMMAP_DECLARE(CtrGamepadButtons, GamepadButton, HidKeyType,
          { GAMEPAD_BUTTON_A,             KEY_A      },
          { GAMEPAD_BUTTON_B,             KEY_B      },
          { GAMEPAD_BUTTON_X,             KEY_X      },
          { GAMEPAD_BUTTON_Y,             KEY_Y      },

          { GAMEPAD_BUTTON_DPAD_LEFT,     KEY_DLEFT  },
          { GAMEPAD_BUTTON_DPAD_UP,       KEY_DUP    },
          { GAMEPAD_BUTTON_DPAD_RIGHT,    KEY_DRIGHT },
          { GAMEPAD_BUTTON_DPAD_DOWN,     KEY_DDOWN  },

          { GAMEPAD_BUTTON_START,         KEY_START  },
          { GAMEPAD_BUTTON_BACK,          KEY_SELECT },

          { GAMEPAD_BUTTON_LEFTSHOULDER,  KEY_L      },
          { GAMEPAD_BUTTON_RIGHTSHOULDER, KEY_R      }
        );

        ENUMMAP_DECLARE(CtrGamepadAxes, GamepadAxis, HidAxisType,
          { GAMEPAD_AXIS_LEFTX,        HIDAXIS_LEFTX        },
          { GAMEPAD_AXIS_LEFTY,        HIDAXIS_LEFTY        },
          { GAMEPAD_AXIS_RIGHTX,       HIDAXIS_RIGHTX       },
          { GAMEPAD_AXIS_RIGHTY,       HIDAXIS_RIGHTY       },
          { GAMEPAD_AXIS_TRIGGERLEFT,  HIDAXIS_TRIGGERLEFT  },
          { GAMEPAD_AXIS_TRIGGERRIGHT, HIDAXIS_TRIGGERRIGHT }
        );

        ENUMMAP_DECLARE(CtrGamepadTypes, GamepadType, CFG_SystemModel,
          { GAMEPAD_TYPE_NINTENDO_3DS,        CFG_MODEL_3DS    },
          { GAMEPAD_TYPE_NINTENDO_3DS_XL,     CFG_MODEL_3DSXL  },
          { GAMEPAD_TYPE_NEW_NINTENDO_3DS,    CFG_MODEL_N3DS   },
          { GAMEPAD_TYPE_NINTENDO_2DS,        CFG_MODEL_2DS    },
          { GAMEPAD_TYPE_NEW_NINTENDO_3DS_XL, CFG_MODEL_N3DSXL },
          { GAMEPAD_TYPE_NEW_NINTENDO_2DS_XL, CFG_MODEL_N2DSXL }
        );
        // clang-format on

        using JoystickBase::getConstant;
    };
} // namespace love
