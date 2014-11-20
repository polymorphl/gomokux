function get_nb_match_str(tab, str)
	local nb = 0
	for k, v in pairs(tab) do
		if (str == v) then 
			nb = nb + 1
		end
	end
end