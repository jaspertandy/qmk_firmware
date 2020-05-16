scale = %w[MI_C  MI_Cs  MI_Ds  MI_F   MI_Fs  MI_Gs  MI_As]

scale_offset = 0
scale_round = 0
notes = []

38.times do |n|
    note = scale[scale_offset]
    note = note + "_#{scale_round}" if scale_round > 0
    notes.push(note)
    scale_offset += 1
    if scale[scale_offset].nil?
        scale_offset = 0
        scale_round += 1
    end
end

puts "{ #{notes.join(", ")} }"
