require 'sequel'
require_relative 'login_user'
require_relative 'register_user'

db = Sequel.connect('sqlite://db.db')

# Clean up before test
db[:users].delete

# Test registration
register = RegisterUser.new(db)
success = register.register('alice', 'sixtimesseven')
puts "Register success? - #{success}"

begin
    register.register('_invalid', 'iliketuhtles')
rescue => e
    puts "Correctly validated invalid username."
end

# Test logging in
login = LoginUser.new(db)
success = login.login('alice', 'sixtimesseven')
puts "Login success? - #{success}"
