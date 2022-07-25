############################################
# Stage 1: Archive extraction
############################################
FROM i386/alpine:3.14 as intermediate

RUN apk update
RUN apk add bash sed p7zip

#ADD data/CodeWarrior.exe /data/CodeWarrior.exe
add data/CW_MCU_11_1_Update4_211222.zip /data/CW_update.zip
ADD scripts/xtract2.sh /scripts/xtract.sh

# Extract build files
RUN /scripts/xtract.sh /data/CW_update.zip /buildtools

# Hack: remove space in name for MSL 58600E stuff
RUN mv "/buildtools/MCU/M56800E Support" "/buildtools/MCU/M56800E_Support"

############################################
# Stage 2: Create the build env.
############################################

FROM i386/alpine:3.14

# Copy extracted buildtools
COPY --from=intermediate /buildtools /buildtools

# Install stuff
RUN apk update
RUN apk add ninja cmake wine

# Wine init
ENV WINEARCH=win32
ENV WINEPREFIX=/root/.wine
ENV WINEDEBUG=fixme-all,err-all

RUN /bin/ash -c "winecfg 2>/dev/err"

# Add scripts files
ADD data/scripts/cc   /buildtools/scripts/cc
ADD data/scripts/asm  /buildtools/scripts/asm
ADD data/scripts/link /buildtools/scripts/link
ADD data/cmake/       /buildtools/cmake
