function parse_word(str)
	local tab = {}
	for w in str:gmatch("%w+") do
		table.insert(tab, w)
	end
	return tab
end