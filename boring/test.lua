local test = {
  opt = 1
}

local test2 = {
}

print(test.opt)

for key, value in pairs(test) do
  test2[key] = value
  print(value)
end

print(test2["opt"])

for key, value in pairs(test2) do
  print(key)
  print(value)
end
