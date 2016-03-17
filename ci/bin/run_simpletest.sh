#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Run the Simpletest tests.
#
# ---------------------------------------------------------------------------- #


# No need for SimpleTest if the profile is not installed.
if [ $INSTALL_PROFILE != 1 ]; then
 exit 0;
fi

# Do we have a tag to run?
if [ $SIMPLETEST != 1 ]; then
  exit 0
fi


# Enable the simpletest module.
drush @capacity4more -y en simpletest

# Run all tests tagged with the distribution name.
cd $TRAVIS_BUILD_DIR/web

echo "PHP SETTINGS"

php scripts/run-tests.sh  --php /home/travis/.phpenv/shims/php "capacity4more"
