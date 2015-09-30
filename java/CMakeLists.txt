SET(STABLE_JAR_FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME_LOWERCASE}-${RST_VERSION}.jar" )
SET(SANDBOX_JAR_FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME_LOWERCASE}sandbox-${RST_VERSION}.jar")
SET(DEPRECATED_JAR_FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME_LOWERCASE}deprecated-${RST_VERSION}.jar")
SET(JAR_FILES ${STABLE_JAR_FILE} ${SANDBOX_JAR_FILE} ${DEPRECATED_JAR_FILE})

FIND_PROGRAM(ANT_EXECUTABLE ant)
IF(ANT_EXECUTABLE AND PROTOBUF_JAVA_LIBRARY)

    SET_PROPERTY(GLOBAL APPEND PROPERTY ENABLED_FEATURES "java binding")

    SET_DIRECTORY_PROPERTIES(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "classes-stable;classes-sandbox;classes-deprecated;stable;sandbox;deprecated")

    PROTOBUF_GENERATE(JAVA STABLE_PROTO_FILES
                      PROTOFILES ${STABLE_PROTOS}
                      PROTOROOT ${STABLE_ROOT}
                      JAVA_FILENAME_SUFFIX "Type.java"
                      DEPENDS "stable_protos"
                      OUTPATH "${CMAKE_CURRENT_BINARY_DIR}/stable")
    PROTOBUF_GENERATE(JAVA SANDBOX_PROTO_FILES
                      PROTOFILES ${SANDBOX_PROTOS}
                      PROTOROOT ${SANDBOX_ROOT}
                      INCLUDES ${STABLE_ROOT}
                      JAVA_FILENAME_SUFFIX "Type.java"
                      DEPENDS "sandbox_protos" "stable_protos"
                      OUTPATH "${CMAKE_CURRENT_BINARY_DIR}/sandbox")
    PROTOBUF_GENERATE(JAVA DEPRECATED_PROTO_FILES
                      PROTOFILES ${DEPRECATED_PROTOS}
                      PROTOROOT ${DEPRECATED_ROOT}
                      INCLUDES ${STABLE_ROOT} ${SANDBOX_ROOT}
                      JAVA_FILENAME_SUFFIX "Type.java"
                      DEPENDS "deprecated_protos" "stable_protos" "sandbox_protos"
                      OUTPATH "${CMAKE_CURRENT_BINARY_DIR}/deprecated")

    # Prepare safe variables and configure ant build files.
    STRING(REPLACE "&" "&amp;" SAFE_CMAKE_CURRENT_BINARY_DIR  "${CMAKE_CURRENT_BINARY_DIR}")
    STRING(REPLACE "&" "&amp;" JAR_LINES "<jar jarfile=\"${STABLE_JAR_FILE}\" basedir=\"classes-stable\" manifest=\"MANIFEST.MF\"><fileset dir=\"${CMAKE_SOURCE_DIR}/proto/stable\"><include name=\"**/*.proto\"/></fileset></jar>\n
<jar jarfile=\"${SANDBOX_JAR_FILE}\" basedir=\"classes-sandbox\" manifest=\"MANIFEST.MF\"><fileset dir=\"${CMAKE_SOURCE_DIR}/proto/sandbox\"><include name=\"**/*.proto\"/></fileset></jar>\n
<jar jarfile=\"${DEPRECATED_JAR_FILE}\" basedir=\"classes-deprecated\" manifest=\"MANIFEST.MF\"><fileset dir=\"${CMAKE_SOURCE_DIR}/proto/deprecated\"><include name=\"**/*.proto\"/></fileset></jar>")
    CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/build.xml.in"
                   "${CMAKE_CURRENT_BINARY_DIR}/build.xml"
                   @ONLY)
    CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/MANIFEST.MF.in"
                   "${CMAKE_CURRENT_BINARY_DIR}/MANIFEST.MF"
                   @ONLY)

    # maven poms
    IF(RST_IS_RELEASE)
        IF(RST_VERSION_PATCH EQUAL 0)
            # it seems the maven convention is to leave out the revision / patch
            # version in case it is 0
            SET(RST_MVN_VERSION "${RST_VERSION_MAJOR}.${RST_VERSION_MINOR}")
        ELSE()
            SET(RST_MVN_VERSION ${RST_VERSION})
        ENDIF()
        SET(RST_MVN_UPSTREAM_VERSION "[${RST_MVN_VERSION}]")
    ELSE()
        SET(RST_MVN_VERSION "${RST_VERSION_MAJOR}.${RST_VERSION_MINOR}-SNAPSHOT")
        SET(RST_MVN_UPSTREAM_VERSION "${RST_MVN_VERSION}")
    ENDIF()
    CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/pom-stable.xml.in"
                   "${CMAKE_CURRENT_BINARY_DIR}/pom-stable${RST_VERSION}.xml"
                   @ONLY)
    CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/pom-sandbox.xml.in"
                   "${CMAKE_CURRENT_BINARY_DIR}/pom-sandbox${RST_VERSION}.xml"
                   @ONLY)
    CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/pom-deprecated.xml.in"
                   "${CMAKE_CURRENT_BINARY_DIR}/pom-deprecated${RST_VERSION}.xml"
                   @ONLY)
    INSTALL(FILES "${CMAKE_CURRENT_BINARY_DIR}/pom-stable${RST_VERSION}.xml"
                  "${CMAKE_CURRENT_BINARY_DIR}/pom-sandbox${RST_VERSION}.xml"
                  "${CMAKE_CURRENT_BINARY_DIR}/pom-deprecated${RST_VERSION}.xml"
            DESTINATION share/java)

    ADD_CUSTOM_COMMAND(OUTPUT  ${JAR_FILES}
                       COMMAND ${ANT_EXECUTABLE} dist
                       DEPENDS ${STABLE_PROTO_FILES} ${SANDBOX_PROTO_FILES} ${DEPRECATED_PROTO_FILES}
                               "${CMAKE_CURRENT_BINARY_DIR}/build.xml" "${CMAKE_CURRENT_BINARY_DIR}/MANIFEST.MF"
                       COMMENT "Creating jar files")
    ADD_CUSTOM_TARGET(java ALL DEPENDS ${JAR_FILES})

    INSTALL(FILES ${JAR_FILES} DESTINATION share/java)

ELSE()
    MESSAGE(STATUS "ant not found or protobuf java library not available. Java bindings will not be created")
ENDIF()
