function construct_map()
	local map = {}

	for i=1, 19 do
		table.insert(map, {})
		for j=1, 19 do
			table.insert(map[i], stack[i * j])
		end
	end
	return map
end