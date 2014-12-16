function display_tab(tab)
	print(tab[1])
	for k = 1, #tab do
		print(k, "[" .. tab[k] .. "]")
	end
end

function display_2dtab(tab)
	for k = 1, #tab do
		if k > 9 then
			io.write(k .. "  " .. #tab .. "   ")
		else
			io.write(k .. "   " .. #tab .. "   ")
		end
		for w = 1, #tab[k] do
			io.write("[" .. tab[k][w] .. "]")
		end
		io.write("\n")
	end
end
