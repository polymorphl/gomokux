dofile("utils/bool.lua")
dofile("utils/display.lua")
dofile("utils/getters.lua")
dofile("utils/parse.lua")
dofile("utils/utils.lua")

-- begin

FREE = 1
TEAM1 = 2
TEAM2 = 3
NOWAY = 4

ME = 0

function min_max()
	return 50
end

function ai()
	ME = arg["team"]
	map = construct_map(arg["map"])
	print_tab();
end

return ai()