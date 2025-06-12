alias -a I = info local
alias -a V = display

define FC
	focus next
end

define map
	display x
	display y
	display data.map[x]
	display data.map[x][y]
end

define map_copy
	display x
	display y
	display map_copy[x]
	display map_copy[x][y]
end
