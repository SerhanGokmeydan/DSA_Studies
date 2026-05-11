# Header (.hpp) dosyalarının olduğu klasörü belirt
include_directories(include)

# Kaynak dosyalarını listele
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Dosyaları birleştirerek tek bir program oluştur
add_executable(Linked_List_App ${SOURCES})

# Çıktıyı ana build klasörünün altındaki Linked_List klasörüne koy
set_target_properties(Linked_List_App PROPERTIES 
    OUTPUT_NAME "main"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Linked_List")