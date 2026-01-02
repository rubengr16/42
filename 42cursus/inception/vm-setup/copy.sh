cd ~/Desktop
cp -rf /media/sf_inception/ .
mv sf_inception inception
cd inception
find * -type f -exec chmod 664 {} \;
unzip ~/Desktop/sensible-data.zip -d srcs
rsync -a srcs/sensible-data/ srcs/
rm -r srcs/sensible-data
