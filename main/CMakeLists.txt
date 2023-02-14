# idf_component_register(SRCS "app_main.c"
# INCLUDE_DIRS ".")
set(COMPONENT_SRCS "app_main.c")
set(COMPONENT_ADD_INCLUDEDIRS "")
set(COMPONENT_REQUIRES soc nvs_flash ulp driver)
register_component()

# -----------ULP-----------
set(ulp_app_name ulp_${COMPONENT_NAME})
set(ulp_riscv_sources "ulp/main.c")
set(ulp_exp_dep_srcs "app_main.c")

ulp_embed_binary(${ulp_app_name} "${ulp_riscv_sources}" "${ulp_exp_dep_srcs}")

# -------------------------