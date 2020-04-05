local _G = _G

Ext._LoadedFiles = {}
Mods = {}

Ext._WarnDeprecated = function (msg)
	Ext.PrintError(msg)
	Ext.PrintError("See https://github.com/Norbyte/ositools/blob/master/LuaAPIDocs.md#migrating-from-v41-to-v42 for more info.")
end

Ext._Notify = function (event)
    for i,callback in pairs(Ext._Listeners[event]) do
        local status, err = xpcall(callback, debug.traceback)
        if not status then
            Ext.PrintError("Error during " .. event .. ": ", err)
        end
    end
end

Ext._EngineCallback1 = function (event, ...)
    for i,callback in pairs(Ext._Listeners[event]) do
        local status, result = xpcall(callback, debug.traceback, ...)
        if status then
			if result ~= nil then
				return result
			end
		else
            Ext.PrintError("Error during " .. event .. ": ", result)
        end
    end
end

Ext._OnGameSessionLoading = function ()
    Ext._Notify("SessionLoading")
end

Ext._OnGameSessionLoaded = function ()
    Ext._Notify("SessionLoaded")
end

Ext._OnModuleLoading = function ()
    Ext._Notify("ModuleLoading")
end

Ext._OnModuleResume = function ()
    Ext._Notify("ModuleResume")
end

Ext._GetHitChance = function (...)
    return Ext._EngineCallback1("GetHitChance", ...)
end

Ext._NetListeners = {}

Ext.RegisterNetListener = function (channel, fn)
	if Ext._NetListeners[channel] == nil then
		Ext._NetListeners[channel] = {}
	end

	table.insert(Ext._NetListeners[channel], fn)
end

Ext._NetMessageReceived = function (channel, payload)
	if Ext._NetListeners[channel] ~= nil then
		for i,callback in pairs(Ext._NetListeners[channel]) do
			local ok, err = xpcall(callback, debug.traceback, channel, payload)
			if not ok then
				Ext.PrintError("Error during NetMessageReceived: ", err)
			end
		end
	end
end

Ext.Require = function (mod, path)
	if ModuleUUID == nil then
		Ext.PrintWarning("Calling Ext.Require() after the module was loaded is deprecated!");
	end

	local fullName
	if path == nil then
		fullName = ModuleUUID .. "/" .. mod
	else
		fullName = mod .. "/" .. path
	end

	if Ext._LoadedFiles[fullName] ~= nil then
		return Ext._LoadedFiles[fullName]
	end

	local loaded
	if path == nil then
		loaded = {Ext.Include(ModuleUUID, mod, nil)}
	else
		loaded = {Ext.Include(mod, path, nil)}
	end

	Ext._LoadedFiles[fullName] = loaded
	return table.unpack(loaded)
end

Ext._LoadBootstrap = function (path, modTable)
	local env = {
		-- Put frequently used items directly into the table for faster access
		type = type,
		tostring = tostring,
		tonumber = tonumber,
		pairs = pairs,
		ipairs = ipairs,
		print = print,
		error = error,
		next = next,

		string = string,
		math = math,
		table = table,

		Ext = Ext,
		Osi = Osi,
		Game = Game,
		Sandboxed = true
	}
	-- The rest are accessed via __index
	setmetatable(env, {__index = _G})
	Mods[modTable] = env

	Ext.Include(ModuleUUID, path, env)
end
