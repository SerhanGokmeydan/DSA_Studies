# Array klasöründeki tüm .cpp dosyalarını bul
file(GLOB ARRAY_FILES "*.cpp")

foreach(FILE IN LISTS ARRAY_FILES)
    get_filename_component(NAME ${FILE} NAME_WE) 
    
    # Her bir .cpp dosyasından bir program (exe) oluştur
    add_executable(Array_${NAME} ${FILE})
    
    # Çıktıları ana build klasörünün altındaki Array klasörüne koy
    set_target_properties(Array_${NAME} PROPERTIES 
        OUTPUT_NAME "${NAME}"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Array")
endforeach()