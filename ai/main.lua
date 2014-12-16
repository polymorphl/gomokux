dofile("ai/utils/display.lua")
dofile("ai/utils/bool.lua")
dofile("ai/utils/getters.lua")
dofile("ai/utils/parse.lua")
dofile("ai/utils/utils.lua")
dofile("ai/utils/display.lua")
dofile("ai/map.lua")

-- begin

FREE = 1
TEAM1 = 2
TEAM2 = 3
NOWAY = 4

ME = 0

function min_max()
end

function ai()
	local map = construct_map()
	display_2dtab(map);

	return -20
end

return ai()
