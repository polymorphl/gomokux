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



function max(map, profondeur)
	if (pronfondeur == 0 || check_win(map) != 0)
	   	return eval(map)
	end
	local max = -1000
	local tmp
	 
	for k = 1, #map do
	      	for w = 1, #map[k] do
		      		if map[k][w] == 1 then
					   	    map[k][w] = TEAM2
					     	tmp = min(map, profondeur - 1)
			     	     
					     	if tmp > max then
				        		max = tmp
			    		 	end
						map[k][w] = FREE
					end
			end
	end

	return max
end

function min(map, profondeur)
	if (pronfondeur == 0 || check_win(map) != 0)
	   	return eval(map)
	end
	local min = 1000
	local tmp
	 
	for k = 1, #map do
	      	for w = 1, #map[k] do
			      	if map[k][w] == 1 then
				   	    	map[k][w] = TEAM2
			     	    	tmp = max(map, profondeur - 1)
			     	     
			     	    	if tmp < min then
				     	    	   min = tmp
			     	    	end
				    		map[k][w] = FREE
					end
			end
	end

	return min
end

function min_max(map)
	local max = -1000
	local tmp, maxY, maxX
	local profondeur = 3

	for k = 1, #map do
	      	for w = 1, #map[k] do
			      	if map[k][w] == 1 then
			   	    		map[k][w] = TEAM2
			     	    	tmp = min(map, profondeur - 1)
			     	     
			     	    	if tmp > max then
			     	     	    	max = tmp
					    			maxY = k
					    			maxX = w
			     	    	end
				    		map[k][w] = FREE
					end
			end
	end
	
	-- return formule avec maxY et maxX
	return -20
end

function ai()
	local three = stack["three"]
	local five = stack["five"]
	local map = construct_map()
	display_2dtab(map);
	
	return min_max(map)
end

return ai()
