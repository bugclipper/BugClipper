Pod::Spec.new do |s|
  s.name     = 'BugClipper'
  s.version  = '1.0.6'
  s.summary = "BugClipper SDK for iOS applications"
  s.description = <<-DESC
                  Visit http://www.bugclipper.com to get a key.
                  DESC
  s.homepage = "http://www.bugclipper.com"
  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
                Copyright (c) 2013-2014, BugClipper Technologies.
                All rights reserved.
    LICENSE
  }
  s.summary  = 'BugClipper SDK for iOS applications'
  s.homepage = 'http://www.bugclipper.com'
  s.author   = { 'Puneet Sharma' => 'puneet.sharma@bugclipper.com' }
  s.social_media_url = "http://www.twitter.com/bugclipper"
  s.source       = { 
                    :git => "https://github.com/bugclipper/BugClipper.git", 
                    :tag => s.version 
                    }
  s.platform = :ios, 6.0
  s.requires_arc = true

  s.ios.vendored_frameworks = 'BugClipper.framework'
  s.frameworks     = 'AVFoundation', 'CoreGraphics', 'CoreMedia', 'CoreVideo', 'MobileCoreServices', 'QuartzCore', 'SystemConfiguration'

end