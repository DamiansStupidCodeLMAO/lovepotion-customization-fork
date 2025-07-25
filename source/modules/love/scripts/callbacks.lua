R"luastring"--(
-- DO NOT REMOVE THE ABOVE LINE. It is used to load this file as a C++ string.
-- There is a matching delimiter at the bottom of the file.

--[[
Copyright (c) 2006-2024 LOVE Development Team

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
--]]

local love = require("love")

function love.createhandlers()
    -- Standard callback handlers.
    love.handlers = setmetatable({
        keypressed = function(b, s, r)
            if love.keypressed then return love.keypressed(b, s, r) end
        end,
        keyreleased = function(b, s)
            if love.keyreleased then return love.keyreleased(b, s) end
        end,
        textinput = function(t)
            if love.textinput then return love.textinput(t) end
        end,
        textedited = function(t, s, l)
            if love.textedited then return love.textedited(t, s, l) end
        end,
        mousemoved = function(x, y, dx, dy, t)
            if love.mousemoved then return love.mousemoved(x, y, dx, dy, t) end
        end,
        mousepressed = function(x, y, b, t, c)
            if love.mousepressed then return love.mousepressed(x, y, b, t, c) end
        end,
        mousereleased = function(x, y, b, t, c)
            if love.mousereleased then return love.mousereleased(x, y, b, t, c) end
        end,
        wheelmoved = function(x, y, px, py, dir)
            if love.wheelmoved then return love.wheelmoved(x, y, px, py, dir) end
        end,
        touchpressed = function(id, x, y, dx, dy, p, t, m)
            if love.touchpressed then return love.touchpressed(id, x, y, dx, dy, p, t, m) end
        end,
        touchreleased = function(id, x, y, dx, dy, p, t, m)
            if love.touchreleased then return love.touchreleased(id, x, y, dx, dy, p, t, m) end
        end,
        touchmoved = function(id, x, y, dx, dy, p, t, m)
            if love.touchmoved then return love.touchmoved(id, x, y, dx, dy, p, t, m) end
        end,
        joystickpressed = function(j, b)
            if love.joystickpressed then return love.joystickpressed(j, b) end
        end,
        joystickreleased = function(j, b)
            if love.joystickreleased then return love.joystickreleased(j, b) end
        end,
        joystickaxis = function(j, a, v)
            if love.joystickaxis then return love.joystickaxis(j, a, v) end
        end,
        joystickhat = function(j, h, v)
            if love.joystickhat then return love.joystickhat(j, h, v) end
        end,
        gamepadpressed = function(j, b)
            if love.gamepadpressed then return love.gamepadpressed(j, b) end
        end,
        gamepadreleased = function(j, b)
            if love.gamepadreleased then return love.gamepadreleased(j, b) end
        end,
        gamepadaxis = function(j, a, v)
            if love.gamepadaxis then return love.gamepadaxis(j, a, v) end
        end,
        joystickadded = function(j)
            if love.joystickadded then return love.joystickadded(j) end
        end,
        joystickremoved = function(j)
            if love.joystickremoved then return love.joystickremoved(j) end
        end,
        joysticksensorupdated = function(j, sensorType, x, y, z)
            if love.joysticksensorupdated then return love.joysticksensorupdated(j, sensorType, x, y, z) end
        end,
        focus = function(f)
            if love.focus then return love.focus(f) end
        end,
        mousefocus = function(f)
            if love.mousefocus then return love.mousefocus(f) end
        end,
        visible = function(v)
            if love.visible then return love.visible(v) end
        end,
        exposed = function()
            if love.exposed then return love.exposed() end
        end,
        occluded = function()
            if love.occluded then return love.occluded() end
        end,
        quit = function()
            return
        end,
        threaderror = function(t, err)
            if love.threaderror then return love.threaderror(t, err) end
        end,
        resize = function(w, h)
            if love.resize then return love.resize(w, h) end
        end,
        filedropped = function(f, x, y)
            if love.filedropped then return love.filedropped(f, x, y) end
        end,
        directorydropped = function(dir, x, y)
            if love.directorydropped then return love.directorydropped(dir, x, y) end
        end,
        dropbegan = function()
            if love.dropbegan then return love.dropbegan() end
        end,
        dropmoved = function(x, y)
            if love.dropmoved then return love.dropmoved(x, y) end
        end,
        dropcompleted = function(x, y)
            if love.dropcompleted then return love.dropcompleted(x, y) end
        end,
        lowmemory = function()
            if love.lowmemory then love.lowmemory() end
            collectgarbage()
            collectgarbage()
        end,
        displayrotated = function(display, orient)
            if love.displayrotated then return love.displayrotated(display, orient) end
        end,
        localechanged = function()
            if love.localechanged then return love.localechanged() end
        end,
        audiodisconnected = function(sources)
            if not love.audiodisconnected or not love.audiodisconnected(sources) then
                love.audio.setPlaybackDevice()
            end
        end,
        sensorupdated = function(sensorType, x, y, z)
            if love.sensorupdated then return love.sensorupdated(sensorType, x, y, z) end
        end,
    }, {
        __index = function(self, name)
            error("Unknown event: " .. name)
        end,
    })
end

-----------------------------------------------------------
-- Default callbacks.
-----------------------------------------------------------

---Gets the stereoscopic 3D value of the 3D slide on Nintendo 3DS
---@param screen string The current screen
---@return number | nil depth The stereoscopic 3D value (0.0 - 1.0)
local function get_stereoscopic_depth(screen)
    if love._console ~= "3DS" then return end
    local depth = love.graphics.getDepth()
    return screen ~= "bottom" and (screen == "left" and depth or -depth) or 0
end

function love.run()
    if love.load then love.load(love.parsedGameArguments, love.rawGameArguments) end

    -- We don't want the first frame's dt to include time taken by love.load.
    if love.timer then love.timer.step() end

    -- Main loop time.
    return function()
        -- Process events.
        if love.event then
            love.event.pump()
            for name, a, b, c, d, e, f, g, h in love.event.poll() do
                if name == "quit" then
                    if not love.quit or not love.quit() then
                        return a or 0, b
                    end
                end
                love.handlers[name](a, b, c, d, e, f, g, h)
            end
        end

        -- Update dt, as we'll be passing it to update
        local dt = love.timer and love.timer.step() or 0

        -- Call update and draw
        if love.update then love.update(dt) end -- will pass 0 if love.timer is disabled

        if love.graphics and love.graphics.isActive() then
            for display_index = 1, love.window.getDisplayCount() do
                local display_name = love.window.getDisplayName(display_index)
                love.graphics.setActiveScreen(display_name)

                love.graphics.origin()

                love.graphics.clear(love.graphics.getBackgroundColor())
                local stereoscopic_depth = get_stereoscopic_depth(display_name)

                if love.draw then love.draw(display_name, stereoscopic_depth) end
                love.graphics.copyCurrentScanBuffer()
            end
            love.graphics.present()
        end
        if love.timer then love.timer.sleep(0.001) end
    end
end

local debug, print, tostring, error = debug, print, tostring, error

function love.threaderror(t, err)
    error("Thread error (" .. tostring(t) .. ")\n\n" .. err, 0)
end

local utf8 = require("utf8")

local function error_printer(msg, layer)
    print((debug.traceback("Error: " .. tostring(msg), 1 + (layer or 1)):gsub("\n[^\n]+$", "")))
end

function love.errhand(msg)
    msg = tostring(msg)

    error_printer(msg, 2)

    if not love.window or not love.graphics or not love.event then
        return
    end

    if not love.graphics.isCreated() or not love.window.isOpen() then
        local success, status = pcall(love.window.setMode, 800, 600)
        if not success or not status then
            return
        end
    end

    -- Reset state.
    if love.mouse then
        love.mouse.setVisible(true)
        love.mouse.setGrabbed(false)
        love.mouse.setRelativeMode(false)
        if love.mouse.isCursorSupported() then
            love.mouse.setCursor()
        end
    end
    if love.joystick then
        -- Stop all joystick vibrations.
        for i, v in ipairs(love.joystick.getJoysticks()) do
            v:setVibration()
        end
    end
    if love.audio then love.audio.stop() end

    love.graphics.reset()
    love.graphics.setFont(love.graphics.newFont(15))

    love.graphics.setColor(1, 1, 1)

    local trace = debug.traceback()

    love.graphics.origin()

    local sanitizedmsg = {}
    for char in msg:gmatch(utf8.charpattern) do
        table.insert(sanitizedmsg, char)
    end
    sanitizedmsg = table.concat(sanitizedmsg)

    local err = {}

    table.insert(err, "Error\n")
    table.insert(err, sanitizedmsg)

    if #sanitizedmsg ~= #msg then
        table.insert(err, "Invalid UTF-8 string in error message.")
    end

    table.insert(err, "\n")

    for l in trace:gmatch("(.-)\n") do
        if not l:match("boot.lua") then
            l = l:gsub("stack traceback:", "Traceback\n")
            table.insert(err, l)
        end
    end

    local p = table.concat(err, "\n")

    p = p:gsub("\t", "")
    p = p:gsub("%[string \"(.-)\"%]", "%1")

    local pos = 70
    local function draw()
        if not love.graphics.isActive() then return end
        for display_index = 1, love.window.getDisplayCount() do
            local display_name = love.window.getDisplayName(display_index)
            love.graphics.setActiveScreen(display_name)
            love.graphics.origin()

            love.graphics.clear(89 / 255, 157 / 255, 220 / 255)

            love.graphics.printf(p, pos, pos, love.graphics.getWidth() - pos)
            love.graphics.copyCurrentScanBuffer()
        end
        love.graphics.present()
    end

    return function()
        love.event.pump()

        for e, a, b, c in love.event.poll() do
            if e == "quit" then
                return 1
            elseif e == "touchpressed" then
                return 1
            end
        end

        draw()

        if love.timer then
            love.timer.sleep(0.1)
        end
    end
end
-- DO NOT REMOVE THE NEXT LINE. It is used to load this file as a C++ string.
--)luastring"--"
