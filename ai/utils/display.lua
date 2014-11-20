function display_tab(tab)
	for k = 1, #tab do
		print(k, "[" .. tab[k] .. "]")
	end
end

function display_2dtab(tab)
	for k = 1, #tab do
		for w = 1, 10 do
			print(k, w, "[" .. tab[k][w] .. "]")
		end
	end
end
