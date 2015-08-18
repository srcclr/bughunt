require 'bcrypt'

class RegisterUser

    # Start with a character or digit, then can include underscores
    VALID_USER = /^[a-zA-Z\d]\w+$/

    def initialize(db)
        @db = db
    end

    def register(username, password)
        raise RuntimeError, 'Invalid username.' unless RegisterUser.is_valid? username

        # Only create user if it doesn't exist
        save_user(username, password) unless get_user(username)
        true
    end

private

    def self.is_valid?(username)
        VALID_USER.match(username)
    end

    def self.get_password_hash(password)
        BCrypt::Password.create(password)
    end

    def get_user(username)
        @db[:users][:username => username]
    end

    def save_user(username, password)
        hash = RegisterUser.get_password_hash(password)
        # Username is validated, and password is hashed. Safe to execute.
        sql = "insert into users (username, password) values (\"#{username}\", \"#{hash}\")"
        @db.run sql
    end

end
