require 'bcrypt'

class LoginUser

    def initialize(db)
        @db = db
    end

    def login(username, password)
        user = get_user(username)
        raise RuntimeError, 'Invalid username.' unless user
        raise RuntimeError, 'Invalid password.' unless LoginUser.valid_login?(user, password)
        true
    end

private

    def self.valid_login?(user, password)
        BCrypt::Password.new(user[:password]) == password
    end

    def get_user(username)
        @db[:users][:username => username]
    end

end

